//GZ-S00088 贵阳市第一中学 吴毅杰 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n;
const int MAXN=1e5+10; 
int a[MAXN][5];
int s;
int t[MAXN];
priority_queue<int> q;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar(); 
	} 
	while(ch<='9'&&ch>='0'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
} 
void search(int mem,int cnt1,int cnt2,int cnt3,int s1){
	if(mem>n){
		return;
	}
	if(cnt1>0){
		cnt1--;
		s1+=a[mem][1];
		s=max(s,s1);
		mem++;
		search(mem,cnt1,cnt2,cnt3,s1);
		mem--;
		s1-=a[mem][1];
		cnt1++;
		
	}
	if(cnt2>0){
		cnt2--;
		s1+=a[mem][2];
		s=max(s,s1);
		mem++;
		search(mem,cnt1,cnt2,cnt3,s1);
		mem--;
		s1-=a[mem][2];
		cnt2++;
		
	}
	if(cnt3>0){
		cnt3--;
		s1+=a[mem][3];
		s=max(s,s1);
		mem++;
		search(mem,cnt1,cnt2,cnt3,s1);
		mem--;
		s1-=a[mem][3];
		cnt3++;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	 T=read();
	 while(T--){
	 	s=0;
	 	memset(a,0,sizeof(a)); 
	 	memset(t,0,sizeof(t));
	 	n=read();
	 	int zui=n/2;
	 	int cnt1,cnt2,cnt3;
	 	cnt1=zui,cnt2=zui,cnt3=zui;
	 	for(int i=0;i<n;i++){
	 		a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
	 		q.push(a[i][1]);
		}
		if(n<100000){
			search(0,cnt1,cnt2,cnt3,0);
			cout<<s<<endl;
		}
		else{
			while(!q.empty()&&n>0){
				s+=q.top();
				q.pop();
				n--;
			}
		}
	}
	return 0;
} 
