#include<bits/stdc++.h>
using namespace std;
string acha(string a,string b){
    int l,r;
    string s;
    for(int i=0;i<int(a.size());i++){
        if(a[i]!=b[i]){
            l=i;
            break;
        }
    }
    for(int j=a.size()-1;j>=0;j--){
        if(a[j]!=b[j]){
            r=j;
            break;
        }
    }
    for(int k=l;k<=r;k++){
        s+=b[k];
    }
    return s;
}
string bcha(string a,string b){
    int l,r;
    string s;
    for(int i=0;i<int(a.size());i++){
        if(a[i]!=b[i]){
            l=i;
            break;
        }
    }
    for(int j=a.size()-1;j>=0;j--){
        if(a[j]!=b[j]){
            r=j;
            break;
        }
    }
    for(int k=l;k<=r;k++){
        s+=a[k];
    }
    return s;
}
struct str{
    string a,b;
};
bool bh(string a,string b){
    bool flag=false;
    for(int i=0;i<int(b.size());i++){
        if(a[0]==b[i]){
            for(int j=0;j<int(a.size());j++){
                flag=true;
                if(a[j]!=b[j+i]){
					//cout<<"no"<<j<<" "<<i;
                    flag=false;
                    break;
                }
            }
            if(flag) return true;
        }
    }
    return false;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    int q,w,ans=0;
    scanf("%d%d",&q,&w);
    str s[q];
    for(int i=0;i<q;i++){
        cin>>s[i].a>>s[i].b;
    }
    while(w--){
        ans=0;
        string x,y;
        cin>>x>>y;
        string acb=acha(x,y);
        string bcb=bcha(x,y);
        for(int i=0;i<q;i++){
            //if(s[i].a==x&&s[i].b==y) ans++;
            if((acb==s[i].b&&bcb==s[i].a)||((bh(bcb,s[i].a)&&int(s[i].a.size())==int(s[i].b.size())&&bh(acb,s[i].b)))) ans++;
        }
        printf("%d\n",ans);
    }
    
    return 0;
}
