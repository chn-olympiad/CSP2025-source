#include<bits/stdc++.h>
using namespace std;
int n,q;
pair <string,string> sd[100010],as[100010];
int main()
{
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
freopen("replace.in", "r", stdin);
freopen("replace.out", "w", stdout);
cin>>n>>q;
for(int i=0;i<n;i++)
cin>>sd[i].first>>sd[i].second;
for(int i=0;i<q;i++){
cin>>as[i].first>>as[i].second;
int li=as[i].first.size(),ans=0;
for(int j=0;j<n;j++){
	int lj=sd[j].first.size();
	if(li<lj)continue;
	else {
		for(int k=0;k<=li-lj;k++){
			int f=0,fk=0;
			for(int h=0;h<k;h++)
				if(as[i].first[h]!=as[i].second[h])f=1;
			for(int h=lj+k;h<li;h++)
				{if(as[i].first[h]!=as[i].second[h])f=1;}
				if(f==1)continue;
		else {
			//cout<<i<<" "<<j<<" "<<k<<'\n';
			for(int h=k;h<lj+k;h++)
			{
				if(as[i].first[h]!=sd[j].first[h-k]){fk=1;break;}
				else if(as[i].second[h]!=sd[j].second[h-k]){fk=1;break;}
				else continue;
			}
			if(fk==0){ans++;/*cout<<i<<" "<<j<<" "<<k<<'\n';*/}
		}
	 }  
   }
}
cout<<ans<<'\n';
}
return 0;
}
