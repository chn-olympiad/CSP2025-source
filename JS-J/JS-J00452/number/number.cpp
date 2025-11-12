#include"bits/stdc++.h"
using namespace std;

string s,q;
int arr[1010];
int k;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

   scanf("%s",&s);
   for(int i=0;i<s.size();i++){
    if(s[i]<97 || s[i]>122){
        arr[k]=int(s[i]);
        k++;
    }
   }
   sort(arr,arr+k);
   for(int i=k;i>=0;i--){
     q.push_back(char(arr[i]));
   }
   printf("%s",q);
    return 0;
}
