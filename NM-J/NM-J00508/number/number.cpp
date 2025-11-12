#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s1;
    cin >> s1;
    if(s1.size()==1){
        cout << s1[0];
        return 0;
    }
    long long s2[1000006];
    long long j=0,a=0;
    string s3;
    int max=0;
    for(long long i=0;i<s1.size();i++){
        if(s1[i]>='0'&&s1[i]<='9'){
            s2[j]=s1[i];
            s2[j]-=48;
            j++;
        }
    }
    for(long long i=0;i<j;i++){
        for(long long r=0;r<j;r++){
            if(max<=s2[r]){
                max=s2[r];
                a=r;
            }
        }
        s2[a]=-1;
        cout << max;
        max=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
