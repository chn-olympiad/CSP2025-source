#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int f[N],book[N];
int n,m,k;
bool dfs(int x,int y){
	if(f[x]==m){
		k=2;
		return true;
	}
    if(y==m){
        k=1;
        return true;
    }
    if(x>n || x<1){
        return false;
    }
    int nx=x+1;
    if(book[nx]==0){
        book[nx]=1;
        dfs(nx,f[nx]^y);
        if(k==0){
            book[nx]=0;
        }
    }
    int ny=x-1;
    if(book[ny]==0){
        book[ny]=1;
        dfs(ny,f[ny]^y);
        if(k==0){
            book[ny]=0;
        }
    }
    if(k==2){
		book[x]=0;
	}
    if(k==1 || k==2){
		return true;
	}
	return false;
}
bool check(int x){
    memset(book,0,sizeof(book));
    int cnt=0;
    for(int i=1;i<=n;i++){
		// for(int i=1;i<=n;i++){
		// 	cout<<book[i]<<" ";
		// }
		// cout<<":"<<cnt<<endl;
        if(f[i]==m && book[i]!=1){
            cnt++;
            book[i]=1;
        }
        if(cnt==x){
			// cout<<cnt<<" "<<x<<endl;
			// cout<<666<<endl;
            return true;
        }
        if(book[i]==0){
            k=0;
            if(dfs(i,f[i])){
				if(k!=2)
                book[i]=1;
                cnt++;
            }
        }
    }
    return false;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>f[i];
    }
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)/2;
        //cout<<l<<" "<<r<<" "<<mid<<endl;
        int ck=check(mid);
        // cout<<ck<<endl;
        if(ck){
            l=mid;
        }else{
            r=mid-1;
        }
        //cout<<endl;
    }
    cout<<l;
    return 0;
}
