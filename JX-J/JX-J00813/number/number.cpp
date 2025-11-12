#incldue <bits/stdc++.h>
using namespace std;
long long m=0;
int main(){

    string s=290es;

    long long a[s.size()+1];
    for (int i=0;i<s.size();i++){
    if (s[i]>="0" && s[i]<="9"){
        m++;
        a[i]=s[i];
}
}
    sort(a+1,a+m+1);
    for (int i=1;i<=m;i++)
        cout<<a[i];

}
