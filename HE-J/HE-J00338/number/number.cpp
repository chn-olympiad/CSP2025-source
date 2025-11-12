#include<bits/stdc++.h> 
using namespace std;
bool cmp(int x,int y){
	return x > y;
}
int main()
{
	string s,a,b;
	int j=0,m=0,minn=-9;
	cin>>s;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int len;
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a[j]=s[i];
			j++;
		}
	}
	for(int i=0;i<j;i++){
	    for(int i=0;i<j;i++){
		    if(a[i]-'0'>minn){
			    minn=a[i]-'0';
			    b[m]=a[i];
		    }
	    }
	    cout<<b[m];
	    for(int i=0;i<j;i++){
		    if(a[i]==b[m]){
			    a[i]=' ';
			    break;
		    }
	    }
	    m++;
	    minn=-9;
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
