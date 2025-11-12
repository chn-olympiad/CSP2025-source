#include<bits/stdc++.h>
using namespace std;
int const N=1e5+1;
int a[N],b[N],c[N];
bool flag=1,flag_2=1;
long long ans;
int T,n;
long long read(){
	char ch=getchar();
	long long res=0;
	int f=1;
	while(!isdigit(ch)){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<1)+(res<<3)+(ch^48);
		ch=getchar();
	}
	return res*f;
}
void print(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		print(x/10);
	}
	putchar((x%10)^48);
}
void dfs(int pos,int cnt_a,int cnt_b,int cnt_c,long long res){
	if(pos==n+1){
		ans=max(ans,res);
		return;
	}
	if(cnt_a<(n>>1)){
		dfs(pos+1,cnt_a+1,cnt_b,cnt_c,res+a[pos]);
	}
	if(cnt_b<(n>>1)){
		dfs(pos+1,cnt_a,cnt_b+1,cnt_c,res+b[pos]);
	}
	if(cnt_c<(n>>1)){
		dfs(pos+1,cnt_a,cnt_b,cnt_c+1,res+c[pos]);
	}
}
void deal(){
	vector<pair<int,int> > veca,vecb;
	bitset<N> bt;
	int cnt_a=0,cnt_b=0;
	for(int i=1;i<=n;i++){
		if(a[i]>b[i]){
			veca.push_back({a[i],i});
		}
		else if(b[i]>a[i]){
			vecb.push_back({b[i],i});
		}
	}
	for(int i=0;i<veca.size();i++){
		if(cnt_a==(n>>1)){
			break;
		}
		int x=veca[i].first,y=veca[i].second;
		ans+=x;
		bt.set(y);
		cnt_a++;
	}
	for(int i=0;i<vecb.size();i++){
		if(cnt_b==(n>>1)){
			break;
		}
		int x=vecb[i].first,y=vecb[i].second;
		ans+=x;
		bt.set(y);
		cnt_b++;
	}
	for(int i=1;i<=n;i++){
		if(!bt[i]){
			if(cnt_a<(n>>1)){
				ans+=a[i];
				bt.set(i);
				cnt_a++;
			}
			if(cnt_b<(n>>1)){
				ans+=b[i];
				bt.set(i);
				cnt_b++;
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		ans=0;
		n=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
			b[i]=read();
			c[i]=read();
			if(b[i]!=0||c[i]!=0){
				flag=0;
			}
			if(c!=0){
				flag_2=0;
			}
		}
		if(flag){
			sort(a+1,a+n+1);
			for(int i=1;i<=(n>>1);i++){
				ans+=a[i];
			}
		}
		else if(flag_2){
			deal();
		}
		else{
			dfs(1,0,0,0,0);
		}
		print(ans);
		putchar('\n');
	}
	return 0;
}