#include<bits/stdc++.h>
using namespace std;
char s[100005];
char a[100005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    int ans=0,sum=0;
    int len=strlen(s);
    for(int i=0;i<len;i++){
    	if(s[i]>='0'&&s[i]<='9'){
    		a[ans]=s[i];
    		ans++;
		}
	}
	for(int i=0;i<ans;i++){
		for(int j=i+1;j<ans;j++){
			if(a[j]>a[i]){
				sum=a[j];
			   a[j]=a[i];
			   a[i]=sum;
			}
		}
	}
	for(int i=0;i<ans;i++){
		cout<<a[i];
	}
	return 0;
}

