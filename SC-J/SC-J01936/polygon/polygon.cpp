#include <bits/stdc++.h>
using namespace std;
int a[4000];
int n,cn=0;
int main (){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int k=1;k<=n-2;k++){
		for(int i=k+2;i<=n;i++){
			int total=0;
			for(int j=k;j<i;j++){
				total+=a[j];
			}
			if(total>a[i]){
				//cout<<k<<i<<endl;
				cn+=1;
				for(int p=k+1;p<i;p++){
					int t1=total;
					for(int q=p;q<i;q++){
						t1-=a[q];
						if(t1>a[i]){
						//cout<<k<<p<<i<<endl;
						cn+=1;
						}

					}
				}
			}
		}
	}
	cout<<cn;

	return 0;
}
