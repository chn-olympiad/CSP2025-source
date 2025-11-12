#include<bits/stdc++.h>
using namespace std;
struct man{
	int bm1,bm2,bm3;
	bool frm_othr;
}a[100010];
int n;
bool cmp(man x,man y){
	int maxx=max(x.bm1,max(x.bm2,x.bm3)),minx=min(x.bm1,min(x.bm2,x.bm3));
	int maxy=max(y.bm1,max(y.bm2,y.bm3)),miny=min(y.bm1,min(y.bm2,y.bm3));
	int midx=x.bm1+x.bm2+x.bm3-maxx-minx;
	int midy=y.bm1+y.bm2+y.bm3-maxy-miny;
	return maxx-midx>maxy-midy;
}
bool cmp2(man x,man y){
	if(x.bm2!=y.bm2) return x.bm2>y.bm2;
	else return max(x.bm1,x.bm3)<max(y.bm1,y.bm3);
}
bool cmp3(man x,man y){
	if(x.bm3!=y.bm3) return x.bm3>y.bm3;
	else return max(x.bm2,x.bm1)<max(y.bm2,y.bm1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		vector<man> bumen1;
		vector<man> bumen2;
		vector<man> bumen3;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].bm1>>a[i].bm2>>a[i].bm3;
			a[i].frm_othr=0;
			int ma=max(a[i].bm1,max(a[i].bm2,a[i].bm3));
			if(ma==a[i].bm1) bumen1.push_back(a[i]);	
			if(ma==a[i].bm2) bumen2.push_back(a[i]);	
			if(ma==a[i].bm3) bumen3.push_back(a[i]);	
		}
		sort(bumen1.begin(),bumen1.end(),cmp);
		sort(bumen2.begin(),bumen2.end(),cmp);
		sort(bumen3.begin(),bumen3.end(),cmp);
		for(int i=n/2;i<bumen1.size();i++){
			if(!bumen1[i].frm_othr){
				if(bumen1[i].bm2>bumen1[i].bm3){
					bumen2.push_back(bumen1[i]);
				}
				else{
					bumen3.push_back(bumen1[i]);
				}
				bumen1[i]={0,0,0};
			}
		}
		for(int i=n/2;i<bumen2.size();i++){
			if(!bumen2[i].frm_othr){
				if(bumen2[i].bm1>bumen2[i].bm3){
					bumen1.push_back(bumen2[i]);
				}
				else{
					bumen3.push_back(bumen2[i]);
				}
				bumen2[i]={0,0,0};
			}
		}
		for(int i=n/2;i<bumen3.size();i++){
			if(!bumen3[i].frm_othr){
				if(bumen3[i].bm1>bumen3[i].bm2){
					bumen1.push_back(bumen3[i]);
				}
				else{
					bumen2.push_back(bumen3[i]);
				}
				bumen3[i]={0,0,0};
			}
		}
		long long sum=0;
		for(int i=0;i<bumen1.size();i++){
			sum+=bumen1[i].bm1;
		}
		for(int i=0;i<bumen2.size();i++){
			sum+=bumen2[i].bm2;
		}
		for(int i=0;i<bumen3.size();i++){
			sum+=bumen3[i].bm3;
		}
		cout<<sum<<'\n'; 
	}
	return 0;
} 
