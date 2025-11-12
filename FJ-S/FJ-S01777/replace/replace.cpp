#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1,s2;
string a[200010],b[200010];
int solve() {
    /*
    ½µµÍÊ±¼ ä¸´ÔÓ¶È
	AC=O(nlogn)||O(n)
	È»ºóÊfÇË ÀÄãÍ»È»Ã»Á ËÂð 


    */
    int ans;
    ans=0;
    return ans;
}
/*
1.À¥¥½ïîí À¥½ïÀf¥d½s ïîí ÌÌ½ïîí À¥½ ïÀ¥½ïîí ÌÌîí ÌÌÀ ¥À¥½ïîí
2. ÌÌ½ïîí ÌÌÌÌsîfíÀ¥½ïî í ÌÌ½ïîí À¥½ïÀ¥½gïîí ÌÌîí ÌÌÀ¥À¥½ïîí 
3.ÌÌ½ïî í ÌsÌdÌfÌ  ÌÌ½ïî í À¥½ïÌgÌîí ÌÌÀ¥À ¥½ïîí ÌÌ½ïîí ÌÌÌÌ 
ÌÌ½ïîí À¥½ ïÀ¥½ïîí ÌÌ4.îí ÌÌÀ¥Àd½ïîí ÌÌ½ïîa í ÌÌÌaÌ 
*/
signed main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1; i<=n; i++) {
        cin>>a[i]>>b[i];
    }
    for(int i=1; i<=q; i++)	{
        cin>>s1>>s2;
        int ans=0;
        string os1=s1,os2=s2;//±©Á¦
        for(int i=1; i<=n; i++) {
            int k=0;
            while(1) {

                //cout<<a[i]<<" "<<k<<" "<<b[i]<<endl;
                //if(s1==a[i]&&a[i]==b[i]&&b[i]==s2) break;
                if(s1.find(a[i],k)==s1.npos) {
                    break;
                } else {
                    k=s1.find(a[i],k)+1;//Æ¥Åä+»¹Ô­
                    for(int j=0; j<int(a[i].size()); j++) {
                        s1[k-1+j]=b[i][j];
                    }
                    if(s1==s2) ans++;
                    for(int j=0; j<int(a[i].size()); j++) {
                        s1[k-1+j]=a[i][j];
                        
                    }


                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


