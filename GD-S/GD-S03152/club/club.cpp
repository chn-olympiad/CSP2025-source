#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
inline int read(){
	int w=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	} 
	while(ch>='0'&&ch<='9') w=w*10+ch-'0',ch=getchar();
	return f*w;
}
int t,n;
struct Node{
	int l[4];
	int x;
}a[N];
int bst(int *l){
	if(l[1]>=max(l[2],l[3])) return 1;
	else if(l[2]>=max(l[1],l[3])) return 2;
	else return 3;
}
int cnt[4]; 
int main(){
//	freopen("club4.in","r",stdin);
//	freopen("club4.out","w",stdout);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		int ans=0;
		for(int i=1;i<=3;i++) cnt[i]=0;
		for(int i=1;i<=n;i++){
			a[i].l[1]=read(),a[i].l[2]=read(),a[i].l[3]=read();
			int sum=a[i].l[1]+a[i].l[2]+a[i].l[3],mx=max({a[i].l[1],a[i].l[2],a[i].l[3]}),mi=min({a[i].l[1],a[i].l[2],a[i].l[3]});
			a[i].x=mx-(sum-mx-mi);
//			cout<<"#"<<mx-(sum-mx-mi)<<endl;
			int b=bst(a[i].l);
			cnt[b]++;
			ans+=mx;
		}
		vector<int> v;
		int w=-1;
//		for(int i=1;i<=3;i++) cout<<cnt[i]<<' ';
//		cout<<endl<<ans<<endl;
		for(int i=1;i<=3;i++){
			if(cnt[i]>n/2){
				w=i;
				for(int j=1;j<=n;j++){
					if(bst(a[j].l)==i) v.push_back(a[j].x);
				} 
			}
		}
		if(~w){
			sort(v.begin(),v.end());
			for(int i=0;cnt[w]>n/2&&i<v.size();i++){
				cnt[w]--;
//				cout<<v[i]<<' ';
				ans-=v[i];
			}
		}
//		cout<<endl;
		printf("%d\n",ans);
	}
	return 0;
}
