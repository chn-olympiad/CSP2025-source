#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
struct node{
	int a,b,c,d;
}s[N];
int f[3][N],cnt[3],o[10];
int sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,n;
	cin>>T;
	while(T--){
		cin>>n;
		sum=0;
		for(int i=0;i<3;i++) cnt[i]=0;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			o[1]=s[i].a;o[2]=s[i].b;o[3]=s[i].c;
			sort(o+1,o+4);
			sum+=o[3];
			s[i].d=o[3]-o[2];
			if(o[3]==s[i].a){ f[0][++cnt[0]]=s[i].d;
			else if(o[3]==s[i].b) f[1][++cnt[1]]=s[i].d;
			else f[2][++cnt[2]]=s[i].d;
		}
		int r=max(cnt[0],max(cnt[1],cnt[2]));
		for(int i=0;i<3;i++){
			if(r==cnt[i]){
				r=i;
				break;
			}
		}
		if(cnt[r]>n/2){
			sort(f[r]+1,f[r]+cnt[r]+1);
			for(int i=1;i<=cnt[r]-n/2;i++) sum-=f[r][i];
		}
		cout<<sum<<"\n";
	}
	return 0;
}
