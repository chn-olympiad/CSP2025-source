#include <iostream>
#include <string>
#include <map>
using namespace std;
map<int,pair<string,string>>ap;
string sub(string pre,int stt,string cng){
	string ovr;
	int i;
	for(i=0;i<stt;i++){
		ovr+=pre[i];
	}
	for(i=stt;i<stt+cng.size();i++){
		ovr+=cng[i-stt];
	}
	for(i=stt+cng.size();i<pre.size();i++){
		ovr+=pre[i];
	}
	return ovr;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		string u,v;
		cin>>u>>v;
		ap[i].first=u;
		ap[i].second=v;
	}
	for(int i=0;i<m;i++){
		string stt,end;
		cin>>stt>>end;
		int sum=0;
		for(int j=0;j<n;j++){
			int hre=stt.find(ap[j].first);
			while(hre>=0){
				string ovr=sub(stt,hre,ap[j].second);
				if(ovr==end)sum++;
				hre=stt.find(ap[j].first,hre+1);
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}