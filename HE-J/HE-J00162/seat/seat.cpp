#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],b,c,ansn,d;
	cin >> n >> m;
	for(int i=0;i < n*m;i++){
		cin >> a[i];
	}
	b=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i < n*m;i++){
		if(a[i]==b){
			c=i;
			break;
		}
	}
	c=c+1;
    ansn=c/n;
    if(c%n!=0){
    	ansn=ansn+1;
	}
	if((c/n)/2!=0){
		d=1;
	}
	if(d==1){
		cout << ansn <<" "<< n-(c%n)-1;
		return 0;
	}
	if(c<=d){
        d=0;
	}
	if(d==0){
        cout << ansn << " " << c;
        return 0;
	}
	cout << ansn << " " << c%n+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
