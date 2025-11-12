#include <bits/stdc++.h>
using namespace std;
pair<string,string>p[200005];
pair<string,string>l[200005];
bool st[200005],flag=true;
long long ans=0;
int main(){
	freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);	
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
	    cin>>p[i].first>>p[i].second;	
	}
	for(int i=1;i<=q;i++){
	    cin>>l[i].first>>l[i].second;
	    for(int j=1;j<=n;j++){
			if((l[i].first.find(p[j].first)==1&&l[i].second.find(p[j].second)==1)||(l[i].first.find(p[j].first)==0&&l[i].second.find(p[j].second)==0)){
				st[j]=true;
			}
		}
	    	
	}
	for(int i=1;i<=q;i++){
	    for(int j=1;j<=n;j++){
		    if(st[j]){
				int len=l[i].first.size(),len1=p[i].first.size();
				for(int k=0;k<len;){
				    if(l[i].first[k]==p[i].first[0]){
						int d=k+len1-1;
						while(k<=d){
							if(l[i].first[k]!=p[i].first[k]){
								flag=false;
								break;
							}
							k++;
						}
						k--;
						if(!flag) break;
					}
					else if(l[i].first[k]!=l[i].second[k]){
						flag=false;
				    }
				    k++;	
				}
				if(flag)ans++;
				flag=true;
		    }
		    
		}	cout<<ans<<endl;
		ans=0;
	}
    return 0;	
}
