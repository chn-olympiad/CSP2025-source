#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long s;
	int i=0,k=10,a[1000005];
	cin>>s;
	for(;;){
		i++;
		a[i]=s%k;
		if(s<10){
			break;
		}
		s/=k;
	}
	sort(a+1,a+1+i);
	for(int j=i;j>=1;j--){
		cout<<a[j];
	}
	fclose(stdin);
	fclose(stdout);
} 
