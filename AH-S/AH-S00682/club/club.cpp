#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int x,y,z;
}a[N];
int n,ans,t[4],flag[N];
int input(){
    char ch=getchar_unlocked();
    int x=0,w=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')w=-1;
        ch=getchar_unlocked();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-48;
        ch=getchar_unlocked();
    }
    return x*w;
}
void output(int x){
    char w[1005];
    int idx=0;
    if(x<0){
        putchar_unlocked('-');
        x=-x;
    }
    do{
        w[++idx]=x%10;
        x/=10;
    }while(x);
    for(int i=idx;i>=1;i--)putchar_unlocked(w[i]+48);
}
bool check(int p){
	if(p>n)return false;
	for(int i=1;i<=3;i++)
		if(t[i]<n/2)return true;
	return false;
}
void dfs(int sum,int num){
	if(!check(num)){
		ans=max(ans,sum);
		return;
	}
	for(int i=num;i<=n;i++){
		if(!flag[i]){
			flag[i]=1;
			if(t[1]<n/2){
				t[1]++;
				dfs(sum+a[i].x,num+1);
				t[1]--;
			}
			if(t[2]<n/2){
				t[2]++;
				dfs(sum+a[i].y,num+1);
				t[2]--;
			}
			if(t[3]<n/2){
				t[3]++;
				dfs(sum+a[i].z,num+1);
				t[3]--;
			}
			flag[i]=0;
		}
	}
	return;
}
bool cmp(node l,node r){
	if(l.x!=r.x)return l.x>r.x;
	else if(l.y!=r.y)return l.y>r.y;
	else return l.z>r.z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=input();
	while(T--){
		n=input();
		ans=0;
		memset(a,0,sizeof a);
		memset(flag,0,sizeof flag);
		t[1]=t[2]=t[3]=0;
		int ea=1;
		for(int i=1;i<=n;i++){
			a[i].x=input();
			a[i].y=input();
			a[i].z=input();
			if(a[i].y!=0||a[i].z!=0)ea=0;
		}
		sort(a+1,a+n+1,cmp);
		if(ea){
			for(int i=1;i<=n/2;i++)ans+=a[i].x;
			output(ans);
			putchar('\n');
			continue;
		}
		dfs(0,1);
		output(ans);
		putchar_unlocked('\n');
	}
	return 0;
}
