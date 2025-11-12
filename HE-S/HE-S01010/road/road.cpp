#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct stu{
	int u,v,w;
};
bool cmp(stu x,stu y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;cin>>n>>m>>k;
	stu z[n];
	int c[k],a[k][n];
	int sum=0;
	string s="";
	int num=100000000;
	for(int i=0;i<m;i++){
		cin>>z[i].u>>z[i].v>>z[i].w;
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	sort(z,z+n,cmp);
	for(int i=0;i<n;i++){
		num=100000000;
		if(s.find("1")==-1||s.find("2")==-1||s.find("3")==-1||s.find("4")==-1||s.size()<5){
			if(s.size()!=4){
				for(int j=0;j<k;j++){
					num=min(num,min(z[i].w,c[j]+a[j][z[i].u-1]+a[j][z[i].v-1]));
				}
				sum+=num;
				s+=(z[i].u+'0');
				s+=(z[i].v+'0');
			}else{
				for(int i=0;i<n;i++){
					for(int j=0;j<k;j++){
						num=min(num,min(z[i].w,c[j]+a[j][z[i].u-1]+a[j][z[i].v-1]));
					}
				}
				sum+=num;
				s+=(z[i].u+'0');
				s+=(z[i].v+'0');
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
