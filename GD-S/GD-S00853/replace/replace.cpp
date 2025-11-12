#include <bits/stdc++.h>
using namespace std;
pair<string,string> rps[500010];
pair<string,string> qus[500010];
unordered_map<string,int> um;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>rps[i].first>>rps[i].second;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>qus[i].first>>qus[i].second;
	}
	for(int i=1;i<=n;i++)
	{
	//	if(rps[i].first.length()<=2000)
	//	{
			int j,k;
			for(j=0;rps[i].first[j]==rps[i].second[j];j++);
			for(k=rps[i].first.length()-1;rps[i].first[k]==rps[i].second[k];k--);
			rps[i].first=rps[i].first.substr(j,k-j+1);
			rps[i].second=rps[i].second.substr(j,k-j+1);
	/*		while(rps[i].first[0]==rps[i].second[0])
			{
				rps[i].first.erase(0,1);
				rps[i].second.erase(0,1);
			}
			while(rps[i].first[rps[i].first.length()-1]==rps[i].second[rps[i].second.length()-1])
			{
				rps[i].first.erase(rps[i].first.length()-1,1);
				rps[i].second.erase(rps[i].second.length()-1,1);
			}*/
	//	}
	/*	else
		{
			int fp=0;
			while(rps[i].first[fp]!='b') fp++;
			int sp=0;
			while(rps[i].second[sp]!='b') sp++;
			if(fp<sp)
			{
				rps[i].first.erase(sp+1);
				rps[i].second.erase(0,fp-1);
			}
		}*/
		string ds=rps[i].first+' '+rps[i].second;
		if(um.find(ds)!=um.end()) um[ds]++;
		else um.emplace(ds,1);
//		cout<<i;
	}
//	cout<<"666";
	for(int i=1;i<=q;i++)
	{
		int j,k;
			for(j=0;qus[i].first[j]==qus[i].second[j];j++);
			for(k=qus[i].first.length()-1;qus[i].first[k]==qus[i].second[k];k--);
			qus[i].first=qus[i].first.substr(j,k-j+1);
			qus[i].second=qus[i].second.substr(j,k-j+1);
		int ans=0;
		string dsq=qus[i].first+' '+qus[i].second;
		if(um.find(dsq)!=um.end()) ans+=um[dsq];
		cout<<ans<<endl;
	}
	return 0;
	
	
	
}
