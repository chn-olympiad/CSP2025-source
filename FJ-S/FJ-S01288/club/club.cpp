#include<bits/stdc++.h>
using namespace std;
struct mem{
	int d1,d2,d3;
	static bool cmp1(mem x,mem y){
		return min(x.d1-x.d2,x.d1-x.d3)<min(y.d1-y.d2,y.d1-y.d3);
	}
	static bool cmp2(mem x,mem y){
		return min(x.d2-x.d1,x.d2-x.d3)<min(y.d2-y.d1,y.d2-y.d3);
	}
	static bool cmp3(mem x,mem y){
		return min(x.d3-x.d1,x.d3-x.d2)<min(y.d3-y.d1,y.d3-y.d2);
	}
};
vector<mem>dp1,dp2,dp3;
int t,n,s1,s2,s3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		s1=s2=s3=0;
		dp1.clear();dp2.clear();dp3.clear();
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			mem x;
			x.d1=a,x.d2=b,x.d3=c;
			if(a>=b&&a>=c){
				dp1.push_back(x);
				s1+=a;
			}
			else if(b>=a&&b>=c){
				dp2.push_back(x);
				s2+=b;
			}
			else{
				dp3.push_back(x);
				s3+=c;
			}
		} 
		//cout<<s1+s2+s3<<endl;
		if(dp1.size()>n/2){
			sort(dp1.begin(),dp1.end(),mem::cmp1);
			for(int i=0;i<dp1.size()-n/2;i++){
				if(dp1[i].d2>=dp1[i].d3){
					s1-=dp1[i].d1;
					s2+=dp1[i].d2;
				} 
				else{
					s1-=dp1[i].d1;
					s3+=dp1[i].d3;
				}
			}
		}
		else if(dp2.size()>n/2){
			sort(dp2.begin(),dp2.end(),mem::cmp2);
			for(int i=0;i<dp2.size()-n/2;i++){
				if(dp2[i].d1>=dp2[i].d3){
					s2-=dp2[i].d2;
					s1+=dp2[i].d1;
				} 
				else{
					s2-=dp2[i].d2;
					s3+=dp2[i].d3;
				}
			}
		}
		else if(dp3.size()>n/2){
			sort(dp3.begin(),dp3.end(),mem::cmp3);
			/*for(int i=0;i<dp3.size();i++){
				mem x=dp3[i];
				cout<<"kkk "<<x.d1<<" "<<x.d2<<" "<<x.d3<<endl;
			}*/
			for(int i=0;i<dp3.size()-n/2;i++){
				if(dp3[i].d1>=dp3[i].d2){
					s3-=dp3[i].d3;
					s1+=dp3[i].d1;
				} 
				else{
					s3-=dp3[i].d3;
					s2+=dp3[i].d2;
				}
			}
		}
		cout<<s1+s2+s3<<endl;
	}
	return 0;
}
