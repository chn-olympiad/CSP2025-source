#include<bits/stdc++.h>
using namespace std;
int arr[1010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R;
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++) {
		cin>>arr[i];
	}
	R=arr[1];
	sort(arr+1,arr+1+len,cmp);
	int l=1,r=1,c=1;
	for(int i=1;i<=len;i++){
		//cout<<l<<' '<<r<<' '<<arr[i]<<'\n';
		if(arr[i]==R){
			cout<<r<<' '<<l<<'\n';
			return 0;
		}
		if(l+c>n || l+c<1) r++,c=-c;
		else l+=c;
	}
	return 0;
}
//#Shang4Shan3Ruo6Shui4
