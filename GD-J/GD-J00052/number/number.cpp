#include<bits/stdc++.h>

using namespace std;
const int N=1e6+10;
int a[N];
int tot;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<int(s.size());i++)
    {
    	if(s[i]>='0' && s[i]<='9'){
    		a[++tot]=int(s[i]-'0');	
			//cout<<s[i]-'0'<<endl;
		}	
	}
	sort(a+1,a+tot+1);
	for(int i=tot;i>=1;i--)
		cout<<a[i];
	cout<<endl;    
	fclose(stdin);
	fclose(stdout);
	return 0;
}

