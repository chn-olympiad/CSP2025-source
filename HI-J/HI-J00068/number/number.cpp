#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];

int main(){ 

	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.size(),i=0,j=0,sum=0;
	while(n){
		if(s[i]>='1'&& s[i]<='9'){
			a[i]=s[i];
			j++;
			sum+=a[j];
		}
	}
    for(int k=0;k<j;k++){
        cout << a[k] 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
