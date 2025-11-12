#include <bits/stdc++.h>
using namespace std;
long long int n,m,s,target;
int a[1000001],loc[10000][10000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	int target=a[1],i=s;
	int h=1,l=1;
	sort(a+1,a+s+1);
	while(i>=0){
		loc[h][l]=a[i];
		if(a[i]==target){
			cout<<l<<" "<<h;
			break;
		}
		if(l&1){
			if(h==n) l++;
			else h++;	
		}
		else{
			if(h==1) l++;
			else h--;
		}
		i--;
	}
	return 0;
}
