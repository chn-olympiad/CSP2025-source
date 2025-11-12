#include<bits/stdc++.h>
using namespace std;
string s[1000005];
string a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int x=s.size();
	for(int i=0;i<=x-1;i++){
        if(s[i]>=0&&s[i]<=9){
            a+=s[i];
        }
	}
    int b=a.size();
    for(int i=0;i<=b-2;i++){
        for(int j=i+1;j<=b-1;j++){
            if(a[i]<a[j]){
                int w=a[i];
                a[i]=a[j];
                a[j]=w;
            }
        }
    }
    for(int i=0;i<=b-1;i++){
        cout<<a[i];
    }
	return 0;
}
