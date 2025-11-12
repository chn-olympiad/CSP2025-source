#include<bits/stdc++.h>
using namespace std;
int n,q;
string t1,t2,s1[100100],s2[100100];
string s;
int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);

	//freopen("replace.in","r",stdin);
	//freopen("replace.out","w",stdout);
	cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>s1[i]>>s2[i];
    }
    while(q--){
        cin>>t1>>t2;
        int cnt=0;
        for(int i=0;i<t1.size();i++){
            for(int j=t1.size()-1;j>i;j--){
                string temp=t1.substr(i,j),temp2=t2.substr(i,j),x1=t1.substr(0,i),x2=t2.substr(0,i),y1=t1.substr(j+1),y2=t1.substr(j+1);
                if(x1!=x2||y1!=y2)continue;
                for(int k=0;k<n;k++){
                    for(int l=0;l<s1[k].size()-k-j+i-1;l++)if(s1[k].substr(k,k+j-i)==temp&&s2[i].substr(k,k+j-i)==temp2){
                        cnt++;
                        break;
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
	return 0;
}

