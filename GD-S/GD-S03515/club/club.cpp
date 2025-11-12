#include<iostream>
#include<algorithm>
#include<cmath>
#include<fstream>
using namespace std;
int T,n,good,i,j,A,B,C,w[3];
struct clb{int a[3],m[3];}arr[100001];
bool cmp(clb a,clb b){
	int mxac,mxbc;
	for(int i=0;i<2;i++){
		mxac=max(mxac,abs(a.a[i]-a.a[i+1]));
		mxbc=max(mxbc,abs(b.a[i]-b.a[i+1]));
	}return mxac>mxbc;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		good=0;
		w[0]=w[1]=w[2]=0;
		for(i=0;i<n;i++){
			arr[i].m[0]=arr[i].m[1]=arr[i].m[2]=1;
			for(j=0;j<3;j++){
				cin>>arr[i].a[j];
				arr[i].m[0]=(arr[i].a[j]>=arr[i].a[arr[i].m[0]]?j:arr[i].m[0]);
				arr[i].m[2]=(arr[i].a[j]<arr[i].a[arr[i].m[2]]?j:arr[i].m[0]);
			}arr[i].m[1]=3-arr[i].m[0]-arr[i].m[2];
		}sort(arr,arr+n,cmp);
		/*for(i=0;i<n;i++){
			for(j=0;j<3;j++) cout<<arr[i].m[j]<<' ';
			cout<<'\n';
		} */
		for(i=0;i<n;i++){
			for(j=0;j<3;j++){
				if(w[arr[i].m[j]]<n/2){
					good+=arr[i].a[arr[i].m[j]];
					w[arr[i].m[j]]++;break;
				}
			}
		}//cout<<w[0]<<' '<<w[1]<<' '<<w[2]<<'\n';
		cout<<good<<'\n';
	}
	
	return 0;
}

