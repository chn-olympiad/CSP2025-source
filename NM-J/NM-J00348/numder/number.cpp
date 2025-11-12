#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.size();
    vector <int> a;
    int j=0;
    for(int i=0;i<n;i++){
            if(s[i]>='0'&&s[i]<='9'){
                a.push_back(int(s[i])-48);
                j++;
            }
    }
    for(int i=0;i<j;i++){
        for(int m=i+1;m<j;m++)
        {

            if(a[i]>a[m]){
                swap(a[i],a[m]);
            }
        }
    }
    for(int i=0;i<j;i++){
        cout<<a.back();
        a.pop_back();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
