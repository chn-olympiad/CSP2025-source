#include<bits/stdc++.h>
using namespace std;
struct student{
	int score;
	int ph;
}a[105];
bool cmp(student x,student y){
	return x.score>y.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int fs=n*m;
	for(int i=1;i<=fs;i++){
		cin>>a[i].score;
	}
	int r=a[1].score;
	sort(a+1,a+fs+1,cmp);
	for(int i=1;i<=fs;i++){
		a[i].ph=i;
	}
	int R,sum=1;
	for(int i=1;i<=fs;i++){
		if(a[i].score==r){
			R=a[i].ph;
			break;
		}
	}
	for(int i=1;i<=fs;i+=n){
		if(i<=R&&i+n>R){
			if(sum%2==0) cout<<sum<<" "<<n-(R-i);
			else cout<<sum<<" "<<R-i+1;
		}
		sum++;
	}
	return 0;
}