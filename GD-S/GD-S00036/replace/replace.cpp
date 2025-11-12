#include<bits/stdc++.h>
using namespace std;
int n,q,sum=0;
string st1,st2;
struct ab{
	string st1,st2;
}a[200001];
int kk[27];
int kd[27];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].st1>>a[i].st2;
	}
	for(int i=1;i<=q;i++){
		cin>>st1>>st2;
		int l,r;
		sum=0;
		for(int j=0;j<st1.size();j++)
		{
			if(st1[j]!=st2[j]) r=j;
		}
		for(int j=st1.size()-1;j>=0;j--) if(st1[j]!=st2[j]) l=j;
		
		for(int x=0;x<=l;x++)
		{
			for(int y=r;y<st1.size();y++){
				string st3="",st4="";
				
				for(int t=x;t<=y;t++){
					st3=st3+st1[t];
					st4=st4+st2[t];
				}//cout<<st3<<" "<<st4<<endl;
				for(int t=1;t<=n;t++)
				{
					if(st3==a[t].st1&&st4==a[t].st2) sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
