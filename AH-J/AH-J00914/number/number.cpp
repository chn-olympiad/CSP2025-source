#include<bits/stdc++.h>
using namespace std;
int StoI(char a){
	return a-'0';
}
bool cmp(int x,int y){
	return x>y;
}
int p[1000000];
int main(){	
	int z=0;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int l=a.size();
    for(int i=0,j=0;i<l;i++)
    {
		if(a[i]>='0'&&a[i]<='9')
		{
			char t=a[i];
			p[j]=StoI(t);
			j++,z++;
		}
	}
	sort(p,p+z,cmp);
	if(p[0]==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=0;i<z;i++) cout<<p[i];
    return 0;
}
