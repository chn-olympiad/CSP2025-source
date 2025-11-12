#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long ln=0,rn=0;
long long a[500005];
vector<int>l;
vector<int>r;
long long temp=0;
int res=0;
int rst=0;
vector<int>ans;
long long ansl=0;
long long lastans=0;
bool vis[500005];
long long xorr(long long lt,long long rt){
    temp=0;
    for(long long i=lt;i<=rt;i++){
        temp=temp^a[i];
    }
    return temp;
}
void visited(long long lt,long long rt){
	for(int i=lt;i<=rt;i++){
		vis[i]=1;
	}
}
bool check(long long lt,long long rt){
	for(int i=lt;i<=rt;i++){
		if(vis[i]==1){
			return true;
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
    for(long long i=1;i<=n;i++){
        for(long long j=i;j<=n;j++){
            if(xorr(i,j)==k){
                l.push_back(i);
                r.push_back(j);
            }
        }
    }
    ln=l.size();
    rn=r.size();
    for(long long i=0;i<ln;i++){
		memset(vis,0,sizeof(vis));
		visited(l[i],r[i]);
		rst=ln;
        for(long long j=i+1;j<rn;j++){
			if(r[i]>=l[j] || l[i]>=r[j] || check(l[j],r[j])){
                res++;
                //cout<<i<<" "<<l[i]<<" "<<r[i]<<" "<<l[j]<<" "<<r[j]<<endl;
            }else{
				visited(l[j],r[j]);
			}
        }
        rst-=res;
        //cout<<i<<" "<<rst<<endl;
        ans.push_back(rst);
    }
    ansl=ans.size();
    for(long long i=0;i<ansl;i++){
        if(lastans<ans[i]){
            lastans=ans[i];
        }
    }
    cout<<lastans;
    cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
