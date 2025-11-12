#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct s{
	long long ip;
	long long g;
};s a[105];
bool cmp(s fu,s ck){
	return fu.g>ck.g;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long ans,nm=n*m,i;
	for(i=1;i<=nm;i++){
		cin>>a[i].g;
		a[i].ip=i;
	}
	sort(a+1,a+nm+1,cmp);
	for(i=1;i<=nm;i++){
		if(a[i].ip==1){
			ans=i;
			break;
		}
	}
	long long mm=ceil(ans*1.0/n),mp=ans-n*(mm-1);
	cout<<mm;
	if(mm%2==0){
		cout<<" "<<n-mp+1;
	}else {
		cout<<" "<<mp;
	}
	return 0;
}
/*
2 2
98 99 100 97


3 3
94 95 96 97 98 99 100 93 92
*/
