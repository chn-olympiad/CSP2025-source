#include<bits/stdc++.h>
using namespace std;
int n,l[5005],sl=0;
bool can(){
	int sum=0,ma=-1;
	for(int i=0;i<sl;i++){
		sum=sum+l[i];
	}
	for(int i=0;i<sl;i++){
		if(l[i]>ma){
			ma=l[i];
		}
	}
	if(sum>2*ma&&sl>2) return 1;
	else return 0;
};
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int a[n],sums=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	//输入 
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int x=0;x<j-i;x++){
				l[x]=a[i+x];
				sl++;
			}
			if(can()==1) sums++;
			cout<<i<<" "<<j<<endl<<sums<<endl;
			for(int y=0;y<sl;y++){
				l[y]=0;
			}
			sl=0;
		}
	}
	cout<<endl<<sums%998244353;
	return 0;
}