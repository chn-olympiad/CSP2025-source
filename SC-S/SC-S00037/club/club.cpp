#include<iostream>
#include<algorithm>

using namespace std;

using ll=long long;
const int N=1e5+5;
struct node{
	int x,y,z,maxx;
	friend bool operator <(const node a,const node b){
		return a.maxx>b.maxx;
	}
};
node stu[N];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			stu[i]={0,0,0,0};
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			stu[i]={x,y,z,0};
			stu[i].maxx=max({x,y,z});
		}
		sort(stu+1,stu+1+n);
		ll sum1=0,sum2=0,sum3=0,cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			if(stu[i].maxx==stu[i].x){
				if(cnt1<n/2){
					sum1+=stu[i].maxx;
					cnt1++;
				}
				else if(stu[i].y>stu[i].z){
					if(cnt2<n/2){
						sum2+=stu[i].y;
						cnt2++;
					}
					else{
						sum3+=stu[i].z;
						cnt3++;
					}
				}
				else{
					if(cnt3<n/2){
						sum3+=stu[i].z;
						cnt3++;
					}
					else{
						sum2+=stu[i].y;
						cnt2++;
					}
				}
			}
			if(stu[i].maxx==stu[i].y){
				if(cnt2<n/2){
					sum2+=stu[i].maxx;
					cnt2++;
				}
				else if(stu[i].x>stu[i].z){
					if(cnt1<n/2){
						sum1+=stu[i].x;
						cnt1++;
					}
					else{
						sum3+=stu[i].z;
						cnt3++;
					}
				}
				else{
					if(cnt3<n/2){
						sum3+=stu[i].z;
						cnt3++;
					}
					else{
						sum1+=stu[i].x;
						cnt1++;
					}
				}
			}
			if(stu[i].maxx==stu[i].z){
				if(cnt3<n/2){
					sum3+=stu[i].maxx;
					cnt3++;
				}
				else if(stu[i].x>stu[i].y){
					if(cnt1<n/2){
						sum1+=stu[i].x;
						cnt1++;
					}
					else{
						sum2+=stu[i].y;
						cnt2++;
					}
				}
				else{
					if(cnt2<n/2){
						sum2+=stu[i].y;
						cnt2++;
					}
					else{
						sum1+=stu[i].x;
						cnt1++;
					}
				}
			}
		}
		cout<<sum1+sum2+sum3<<'\n';
	}
	return 0;
}