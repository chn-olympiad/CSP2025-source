#include <bits/stdc++.h>
using namespace std;
int n,q[5010],sum,s[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polgyon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>q[i];
		s[i]=s[i-1]+q[i];
	}
	if (n==3){
		if ((q[3]+q[1]+q[2])>(*max_element(q,q+n))*2) sum++;
		cout<<sum;
	}
	else {
		sort(q+1,q+n+1);
		for (int i=1;i<=n;i++){
			for (int j=i;j<=n;j++){
				if (s[j+1]-s[i]>(*max_element(q+i+1,q+j+1))*2) sum++;
				
			}
		}
		cout<<sum;
	}
	return 0;
} 
