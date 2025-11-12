#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    vector<string> from(n),to(n);
    vector<int> xs,ys,zs,ws;
    for(int i=0;i<n;i++){
        cin>>from[i]>>to[i];
        bool special2=1;
        for(char i:from[i])if(i!='a'&&i!='b'){special2=0;break;}
        for(char i:to[i])if(i!='a'&&i!='b'){special2=0;break;}
        if(from[i].find('b',from[i].find('b')+1)!=-1)special2=0;
        if(to[i].find('b',to[i].find('b')+1)!=-1)special2=0;
        if(!special2)continue;
        int pos1=from[i].find('b'),pos2=to[i].find('b');
        int x=pos1,y=from[i].size()-pos1-1,z=pos2,w=to[i].size()-pos2-1;
        xs.push_back(x);
        ys.push_back(y);
        zs.push_back(z);
        ws.push_back(w);
    }
    while(q--){
        string s1,s2;
        cin>>s1>>s2;
        bool special=1;
        for(char i:s1)if(i!='a'&&i!='b'){special=0;break;}
        for(char i:s2)if(i!='a'&&i!='b'){special=0;break;}
        if(s1.find('b',s1.find('b')+1)!=-1)special=0;
        if(s2.find('b',s2.find('b')+1)!=-1)special=0;
        //cout<<special;
        int ans=0;
        if(!special){
            if(s1.size()==s2.size()){
                for(int i=0;i<n;i++){
                    int pos=0;
                    pos=s1.find(from[i],0);
                    while(1){
                        if(pos==-1)break;
                        if(pos!=-1&&s2.substr(pos,from[i].size())==to[i]&&s2.substr(0,pos)==s1.substr(0,pos)&&s1.substr(pos+from[i].size())==s2.substr(pos+from[i].size())){
                            ans++;
                        }
                        pos=s1.find(from[i],pos+1);
                    }
                }
            }
            cout<<ans<<"\n";
        }
        else{
            for(int i=0;i<n;i++){
                //cout<<x<<y<<z<<w<<"\n";
                int pos3=s1.find('b'),pos4=s2.find('b');
                int x=xs[i],y=ys[i],z=zs[i],w=ws[i];
                int p=pos3,q=s1.size()-pos3-1,r=pos4,s=s2.size()-pos4-1;
                if(p>=x&&q>=y&&p-x+q==r&&q-y+w==s){
                    ans++;
                }
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
