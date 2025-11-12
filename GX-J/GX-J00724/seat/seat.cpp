#include<iostream>
#include<cstdio>
#include<string>

using namespace std;
int n,m;
int r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&r);
	int sum=1;
	for(int i=2; i<=n*m; i++){
		int x;
		scanf("%d",&x);
		if(x>r) sum++;
	}
	int h;
	int l=sum/n;
	if(sum%n!=0){ l++;
		int ll=sum%n;
		if(l%2==0){
			h=n-ll+1;
		}
		else{
			h=ll;
		}
	}
	else{
		if(l%2==0){
			h=1;
		}
		else{
			h=n;
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
