#include<bits/stdc++.h>
using namespace std;
int mian(){
	freopen("nember.in","r",stdin);
	freopen("nember.out","w",stdout);
	string a;
	cin>>a;
	long long k=a.length();
	long long n[k],m=0;
	for(int i=0;i<k;i++){
		if(i>=46 && i<=55){
			n[m]=i-46;
			m++;
		}
	}
	for(int i=1;i<m;i++){
		for(int j=i+1;j<=m;j++){
			if(a[i]<a[j])
				swap(a[i],a[j]);
		}
	}
	for(int i=0;i<=m;i++){
		cout<<n[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
