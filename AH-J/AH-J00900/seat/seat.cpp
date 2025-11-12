#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b[105];
int c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n*m+1);
	int num=0;
	for(int i=1;i<=n*m;i++){
		if(b[i]==a[1]) num=n*m-i+1;
	}
	int s1=0,s2=0;
	s1=num/n;
	s2=num%n;
	if(s2>0) s1+=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s1%2==1){
				c=s1;
				if(s2==0) r=n;
				if(s2>0) r=s2;
			}
			if(s1%2==0){
				c=s1;
				if(s2==0) r=s2+1;
				if(s2>0) r=m-s2+1;
			}
		}
	}
	cout<<c<<" "<<r;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
