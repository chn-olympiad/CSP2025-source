#include<bits/stdc++.h>
using namespace std;
int n,m,l,ansx,ansy;
int a[116];
int s[110];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d", &n, &m);
	l=n*m;
	for(int i=1;i<=l;i++){
		cin>>a[i];
	}
	int f=a[1];
	sort(a+1,a+l+1,cmp);
	int flag=0;
	for(int i=1;i<=l;i++){
		if(a[i]==f){
			flag=i;
			break;
		}
	}
	int d=flag/n;
	if(flag<=n){
		cout<<"1 "<<flag;
		return 0;
	}
	else if(flag%n==0){
		if(d%2==0){
			cout<<d<<" "<<1;
		}
		else{
			cout<<d<<" "<<n;
		}
	}
	else if(flag%n==1){
		d+=1;
		if(d%2==0){
			cout<<d<<" "<<n;
		}
		else{
			cout<<d<<" "<<1;
		}
	}
	else{
		d+=1;
		if(d%2==0){
			cout<<d<<" "<<n-(flag%n)+1;
		}
		else{
			cout<<d<<" "<<flag%n;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
