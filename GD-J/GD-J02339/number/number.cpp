#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
if(a>b)
{return 1;
}
else{return 0;
}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++)
	{if(!(a[i]>='0'&&a[i]<='9'))
	{a.erase(a.begin()+i);
	i-=1;
	}
	}
	sort(a.begin(),a.end(),cmp);
	cout<<a;
	return 0;
}
  
