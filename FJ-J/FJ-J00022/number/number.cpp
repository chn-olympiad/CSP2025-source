#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	char s[1000001],t,sum;
	cin>>s;
	int len=strlen(s);
	if(len==1&&s[1]>='0'&&s[1]<='9'){
			cout<<s;
			return 0;
		}
		for(int j=0;j<=len;j++){	
		    if(s[j+1]>s[j])
			swap(s[j+1],s[j]);
			for(int k=0;k<=j;k++){
				if(s[k]>s[k+1]&&k==j)
				continue;
				else if(s[k]<s[k+1]) 
				swap(s[k+1],s[k]);
}
}
	for(int i=0;i<=len;i++){
		if(s[i]>='0'&&s[i]<='9')
		cout<<s[i];
	}
	return 0;
}