#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],r,num;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			num++;
			break;
		}
		num++;
	}
	if(num%n==0){
		if((num/n)%2==0){
			cout<<(num/n)<<" "<<1;
			return 0;
		}
		else{
			cout<<(num/n)<<" "<<n;
			return 0;
		}
	}
	else{
		if((num/n)%2==0){
			cout<<(num/n)+1<<" "<<(num%n);
			return 0;
		}
		else{
			if(num%n==1){
				cout<<(num/n)+1<<" "<<n;
				return 0;
			}
			cout<<(num/n)+1<<" "<<n-(num%n);
			return 0;
		}
	}

	return 0;
}

