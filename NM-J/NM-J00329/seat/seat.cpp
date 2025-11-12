#include<bits/stdc++.h>

using namespace std;

int main()
{

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int nm=n*m;
    int a[110];
    int s;
    for (int i=1;i<=nm;i++){
    	cin>>a[i];
    	if (i==1){
    		s=a[i];
		}
    }
    sort(a+1,a+nm+1);
    int j;
    int q=1;
	for (int i=nm;i>0;i--){
		if (a[i]==s){
			j=q;
		}
		q++;
    }
	int A=j/n+1;
	if (j%n==0 ){
		A--;
	}
	int B=j%n;
	if (B==0){
		B=n;

	}
	if (A%2==0){
	    B=n-B+1;
	}
	cout<<A<<" "<<B;
    return 0;
}
