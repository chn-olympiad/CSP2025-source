#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int b[114514];
int c=0;
bool d[114514];
int main(){
	memset(d,false,sizeof(d));
    int n,k;
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int h;
            h = b[i];
            int t = false;
            for(int v=i+1;v<=j;v++){
            	if(d[v]){
            		t = true;
            		break;
				}
                h = h xor b[v];
            }
            if(h==k&&!t){
            	for(int v=i;v<=j;v++){
            	
                d[v]= true;
            	}
            	c++;
			}
        }
    }
    cout<<c;
    return 0;
}
