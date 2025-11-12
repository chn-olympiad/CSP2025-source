#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int ans;
int a[N][4];
void fen5(){
	 int dd=max(a[1][3]+a[2][1],a[1][3]+a[2][2]);
    int cc=max(a[1][2]+a[2][3],dd);
    int bb=max(a[1][1]+a[2][3],cc);
    int aa=max(a[1][2]+a[2][1],bb);
	ans=max(a[1][1]+a[2][2],aa);
	cout<<ans<<'\n';
	return ;
}
void slove(){ 
ans=0;
   int n;
	cin>>n;
//	cout<<"===="<<n<<"===";
	vector<int>a1(n+1,0);
	vector<int>b(n+1,0);
	vector<int>c(n+1,0);
//    for(int i=1;i<=n;i++){
//	a[i]=0;
//	b[i]=0;
//	c[i]=0;
//}
    for(int i=1;i<=n;i++){
		cin>>a1[i]>>b[i]>>c[i];
		a[i][1]=a1[i];
		a[i][2]=b[i];
		a[i][3]=c[i];
	}
	if(n==2){
		fen5();
		return ;
	}
	int now1=n,now2=n,now3=n;
//	cout<<"   "<<now1<<'\n';
	sort(a1.begin(),a1.end());
	sort(b.begin(),b.end());
	sort(c.begin(),c.end());
	for(int i=1;i<=n;i++){
		if(now1==n/2+1){
			for(int j=1;j<=n;j++){
				a1[j]=0;
			}
		}
		if(now2==n/2){
			for(int j=1;j<=n;j++){
				b[j]=0;
			}
		}
		if(now3==n/2){
			for(int j=1;j<=n;j++){
				c[j]=0;
			}
		}
		int jia=max(a1[now1],max(b[now2],c[now3]));
		if(jia==a1[now1]){
			ans+=jia;
			now1--;
		}
		else if(jia==b[now2]){
			ans+=jia;
			now2--;
		}
		else{
			ans+=jia;
			now3--;
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		slove();
	}
	
	return 0;
}
