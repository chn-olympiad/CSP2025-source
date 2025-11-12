#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
long long t,n,a[3][200005],maxx=-1,aa[3];
void dg(long long sum,int num){
	if(num==n){
		maxx=max(maxx,sum);
		return;
	}
	for(int i=0;i<3;i++){
		if(aa[i]<n/2){
			aa[i]++;
			sum+=a[i][num];
			dg(sum,num+1);
			aa[i]--;
			sum-=a[i][num];
		}
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		maxx=-1;
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[j][i];
			}
		}
		dg(0,0);
		cout<<maxx<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
