#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=1e5+10;
int A[maxn];
pair<int,int> B[maxn];
int t , n , cnta , cntb , cntc , ans;
bool cmp(pair<int,int> x,pair<int,int> y){
	if(x.first==y.first){
		return x.second<y.second;
	}
	return x.first<y.first;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>> t;
	while(t--){
		cnta=cntb=cntc=0;
		cin>> n;
		for(int i=1;i <= n;i++){
			int a , b , c;
			cin>> a >> b >> c;
			A[i]=a;B[i]={b-a,c-a};ans+=a;
		}
		sort(B,B+n,cmp);
		for(int i=1;i <= n;i++){
			if(cntb<n/2&&cntc<n/2){
				if(cntc<n/2&&B[i].second>B[i].first){
					ans+=B[i].second;
					cntc++;
				}else{
					ans+=B[i].first;
					cntb++;
				}
			}else if(cntb>=n/2){
				if(cntc<n/2&&B[i].second>0||cnta>=n/2){
					ans+=B[i].second;
					cntc++;
				}else{
					cnta++;
				}
			}else{
				if(cntb<n/2&&B[i].first>0||cnta>=n/2){
					ans+=B[i].first;
					cntb++;
				}else{
					cnta++;
				}
			}
		}
		cout<< ans <<'\n';
	}
	return 0;
}
