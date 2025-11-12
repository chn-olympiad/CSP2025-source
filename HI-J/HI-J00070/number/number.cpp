#include<bits/stdc++.h>
using namespace std;
int a[1000001],b[1000001];
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	int n=s.size(),i=0,j=0,sum=0;
	while(n){
		if(s[i]>='1'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
		i++;
		n--;
	}
	for(int k=0;k<j;k++){
		for(int v=0;v<j;v++){
			if(a[v]>a[k]){
				a[k]=a[v];
				a[v]=0;
			}
		}
	}
	for(int k=0;k<j;k++){
		for(int v=0;v<j;v++){
			if(a[v]>b[k]){
				b[k]=a[v];
			}
		}
	}
	for(int k=0;k<j;k++){
		sum+=a[k]*pow(a[j-k],10);
	}
	cout<<sum;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
