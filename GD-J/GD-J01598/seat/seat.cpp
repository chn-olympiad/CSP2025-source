#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[1000000];
int n,m,x,b,n1,m1=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			x=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			b=i;
		}
	}
	while(true){
		if(b<=n){
			break;
		}
		else{
			b-=n;
			m1++;
		}
	}
	if(m1%2==0){
		n1=n+1;
		while(b){
		    n1--;
		    b--;
	    }
	}
	else{
		while(b){
		    n1++;
		    b--;
	    }
	}
	cout<<m1<<" "<<n1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
