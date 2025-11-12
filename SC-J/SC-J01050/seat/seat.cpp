#include<bits/stdc++.h>
using namespace std;
int n,m,c;
int a[105];
int cm(int a,int b){
	return a>=b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	c=n*m;
	cin>>a[1];
	int d=a[1];
	for(int i=2;i<=c;++i){
		cin>>a[i];
	}
	sort(a+1,a+c+1,cm);
	if(m==1&&n!=1){
		for(int i=1;i<=c;++i){
			if(a[i]==d){
				cout<<1<<" "<<i;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
		}
	}else if(n==1&&m!=1){
		for(int i=1;i<=c;++i){
			if(a[i]==d){
				cout<<i<<" "<<1;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
		}
	}else if(n==1&&m==1){
		cout<<1<<" "<<1;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}