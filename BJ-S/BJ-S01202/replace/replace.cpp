#include <bits/stdc++.h>
using namespace std;
int n,q;
string c[200005][2],t1,t2;
string repl(string a,string b,int t){
    int n=a.length();
    for(int i=0;i<n;i++){
        b[i+t]=a[i];
    }
    return b;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>c[i][0]>>c[i][1];
    }
    while(q--){
        int cnt=0;
        cin>>t1>>t2;
        for(int i=1;i<=n;i++){
            int xe=t1.find(c[i][0]);
            if(xe==-1){
				continue;
			}
            string t3=repl(c[i][1],t1,xe);
			if(t3==t2){
				cnt++;
				continue;
			}
			else{
				int k=xe+1;
				while(xe!=-1){
					xe=t1.find(c[i][0],k);
					if(xe==-1){
						break;
					}
					t3=repl(c[i][1],t1,xe);
					if(t3==t2){
						cnt++;
						break;
					}
					k=xe+1;
				}
			}
        }
        cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
