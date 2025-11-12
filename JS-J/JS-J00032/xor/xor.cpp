#include<bits/stdc++.h>
using namespace std;
int n,k;
int x(vector<int> &a,int b,int e){
    int h=a[b];
    for(int i=b+1;i<=e;i++){
        h=h^a[i];
    }
    return h;
}
struct TreeNode{
    int b,e,v;
    TreeNode* left;
    TreeNode* right;
    TreeNode(TreeNode* l,TreeNode* r,int b,int e,int v):left(l),right(r),b(b),e(e),v(v){}

};
TreeNode* BuildTree(vector<int> &a,int b,int e){
    int res=x(a,b,e);
    TreeNode t(NULL,NULL,b,e,res);
    if(b==e)return &t;
    t.left=BuildTree(a,b,(e+b)/2),t.right=BuildTree(a,(e+b)/2+1,e);
    return &t;
}
int s(TreeNode* bn){
    int num=0;
    if(bn->b==bn->e)return (bn->v==k?1:0);
    if(bn->v==k)num++;
    int num2=s(bn->left)+s(bn->right);
    if(num2>num){
        return num2;
    }
    else{
        return num;
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>k;
    vector<int> v;
    int t;
    for(int i=0;i<n;i++){
        cin>>t;
        v.push_back(t);
    }
    TreeNode* tn=BuildTree(v,0,n-1);
    int tag=s(tn);
    cout<<tag;
    return 0;
}
