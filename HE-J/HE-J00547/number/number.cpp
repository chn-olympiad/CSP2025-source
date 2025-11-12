#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char a[1000005];
    int b=0;
	cin>>s;
	int c=s.size();
	if(c==1){
	    cout<<s;
	    return 0;
	}
	
	for(int i=1;i<=c;i++)
	{
	if((s[i]=1)||(s[i]=2)||(s[i]=3)||(s[i]=4)||(s[i]=5)||(s[i]=6)||(s[i]=7)||(s[i]=8)||(s[i]=9)||(s[i]=0))
		{
		    b++;
			a[b]=s[i];
		}
		 
   	else{
    for(int i=1;i<=b;i++)
	{
		if(a[i]>a[1])
			swap(a[i],a[1]);
		}
		}
		}
	if(b=1){
		cout<<a[b];
		return 0;
	}

	for(int i=1;i<=b;i++)
	cout<<a[i];	
	    
   
	fclose(stdin);
	fclose(stdout);
	return 0;
}
