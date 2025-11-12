#include<bits/stdc++.h>
using namespace std;
struct Node{
    int a1,a2,a3;
};
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int n;
    cin>>n;
    int num;
    Node a[1000];
    int ans=0;
    priority_queue<int> num1;
    priority_queue<int> num2;
    priority_queue<int> num3;

    while(n--){
        cin>>num;
        for(int i=1;i<=num;i++){

            cin>>a[i].a1>>a[i].a2>>a[i].a3;
            num1.push(a[i].a1);
            num1.push(a[i].a2);
            num1.push(a[i].a3);
            ans+=num1.top();
            num1.pop();
            num1.pop();
            num1.pop();

        }

    }
    cout<<ans;
    return 0;
}
