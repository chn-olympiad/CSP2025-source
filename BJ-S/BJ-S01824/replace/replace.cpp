#include<iostream>
#include<cstring>

using namespace std;

int main(){
    int n, q;
    int maxn=200005;
    string s1[maxn], s2[maxn];
    string t1[maxn], t2[maxn];
    int a[maxn];

	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

    cin >> n >> q;
    for(int i=0;i<n;i++){
        cin >> s1[i] >> s2[i];
    }
    for(int j = 0;j < q;j++){
        cin >> t1[j] >> t2[j];
    }


    for(int i=0;i<n;i++){
        a[i]=sizeof(s1[i]);
    }
    while(q){
        int ans = 0;

        for(int i = 0; i < n; i++){
                string s ;
            for(int j = 0; j <= sizeof(t1[i]) - sizeof(s1[i]); j++){
                s += t1[i];
                //if(t1[i][j] == s1[i][j]){
                //    s+=s2[i][j];
                //}else{
                //    s+=t1[i][j];
                //}

            }
            if(s == s1[i]){
                s = s2[i];
                string s1;
                int t = 0;
                for(int j = 0; j <= sizeof(t1[i]) - sizeof(s); j++){
                    if(t1[i][j] == s[j]){
                        s1+=s[j];
                        t = j;
                    }else{
                        s1.clear();
                        t = 0;
                    }
                }
                int na=0;
                for(int k=t-s1.size();k<=t;k++){
                    t1[i][k]=s1[na];
                    na++;
                }
            }
            if(t1[i] == t2[i]){
                ans++;
            }
        }



        cout << ans << endl;
        q--;
    }




	return 0;
}
