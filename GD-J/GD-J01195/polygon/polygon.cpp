#include <iostream>
#include <cstdio>

int main () {
	freopen ("polygen.in", "r", stdin);
	freopen ("polygen.out","w", stdout);
	int n;
	std::cin >> n;
	std::cout << n;
	
	/*
	zhe yi jie ping ce ji zhe me hao hua
	jiu jung jau bit sin dung sat hiu zaam jip sou
	
	jian kao lao shi jin ran yi kai shi bu zhi dao xu ni ji de mi ma
	hao zai hou mian wen(zhao?) dao le
	
	gan jue jin nian hao xiang bi wang nian jian dan (?
	
	360 ya suo ke yi jie ya checker (?
	jin nian checker zen me zhe me jian lou
	
	xia wu hai yao kao s zu
	
	xor bu zhi dao na li nei cun xie lou le
	fsanitize de xin xi bu hui kan (?
	
	number 446B
	seat 572B
	xor 1123B(1.09KB)
	polygon ...
	
	wo de xing wei hen mi huo ma :)
	
gf-noi@gd-noi:/media/sf_public/GD-J01195/xor$ vim xor.cpp
gf-noi@gd-noi:/media/sf_public/GD-J01195/xor$ g++ xor.cpp -o xor -std=c++14 -fsanitize=undefined,address
gf-noi@gd-noi:/media/sf_public/GD-J01195/xor$ ./xor
=================================================================
==3037==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x6020006096b8 at pc 0x56259d7dc3e9 bp 0x7ffd83fca820 sp 0x7ffd83fca810
READ of size 4 at 0x6020006096b8 thread T0
    #0 0x56259d7dc3e8 in main (/media/sf_public/GD-J01195/xor/xor+0xe3e8)
    #1 0x7f323ed900b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
    #2 0x56259d7db58d in _start (/media/sf_public/GD-J01195/xor/xor+0xd58d)

0x6020006096b8 is located 0 bytes to the right of 8-byte region [0x6020006096b0,0x6020006096b8)
allocated by thread T0 here:
    #0 0x7f323fbd4947 in operator new(unsigned long) (/lib/x86_64-linux-gnu/libasan.so.5+0x10f947)
    #1 0x56259d7e1e9c in __gnu_cxx::new_allocator<int>::allocate(unsigned long, void const*) (/media/sf_public/GD-J01195/xor/xor+0x13e9c)
    #2 0x56259d7e17ce in std::allocator_traits<std::allocator<int> >::allocate(std::allocator<int>&, unsigned long) (/media/sf_public/GD-J01195/xor/xor+0x137ce)
    #3 0x56259d7e03ed in std::_Vector_base<int, std::allocator<int> >::_M_allocate(unsigned long) (/media/sf_public/GD-J01195/xor/xor+0x123ed)
    #4 0x56259d7e09fd in void std::vector<int, std::allocator<int> >::_M_realloc_insert<int>(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >, int&&) (/media/sf_public/GD-J01195/xor/xor+0x129fd)
    #5 0x56259d7dfa4b in void std::vector<int, std::allocator<int> >::emplace_back<int>(int&&) (/media/sf_public/GD-J01195/xor/xor+0x11a4b)
    #6 0x56259d7de050 in std::vector<int, std::allocator<int> >::push_back(int&&) (/media/sf_public/GD-J01195/xor/xor+0x10050)
    #7 0x56259d7dc4ff in main (/media/sf_public/GD-J01195/xor/xor+0xe4ff)
    #8 0x7f323ed900b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)

SUMMARY: AddressSanitizer: heap-buffer-overflow (/media/sf_public/GD-J01195/xor/xor+0xe3e8) in main
Shadow bytes around the buggy address:
  0x0c04800b9280: fa fa fd fa fa fa fd fa fa fa fd fa fa fa fd fa
  0x0c04800b9290: fa fa fd fa fa fa fd fa fa fa fd fa fa fa fd fa
  0x0c04800b92a0: fa fa fd fa fa fa fd fa fa fa fd fa fa fa fd fa
  0x0c04800b92b0: fa fa fd fa fa fa fd fa fa fa fd fa fa fa fd fa
  0x0c04800b92c0: fa fa fd fa fa fa fd fa fa fa fd fa fa fa fd fa
=>0x0c04800b92d0: fa fa fd fa fa fa 00[fa]fa fa 00 fa fa fa 00 fa
  0x0c04800b92e0: fa fa 00 fa fa fa 00 fa fa fa 00 fa fa fa 00 fa
  0x0c04800b92f0: fa fa 00 fa fa fa 00 fa fa fa 00 fa fa fa 00 fa
  0x0c04800b9300: fa fa 00 fa fa fa 00 fa fa fa 00 fa fa fa 00 fa
  0x0c04800b9310: fa fa 00 fa fa fa 00 fa fa fa 00 fa fa fa 00 fa
  0x0c04800b9320: fa fa 00 fa fa fa 00 fa fa fa 00 fa fa fa 00 fa
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
  Shadow gap:              cc
==3037==ABORTING

	jin ran ke yi yu xu ni ji jiao hu
	
	abababab
	
	i3-8100 12gb ram (?
	
	hou tian hai you kai ti (>
	
	zuo kuo hao zhen hao wan ((((((((((((((((((((((((
	
	11:37
	
	qwertyuiopasdfghjklzxcvbnm_+{}:"|<>?-=[];'\,./1234567890`~!@#$%^&*()
	
	ping mu guai guai de
	dan you shuo bu chu na li guai
	
	bang wo tiao tiao t3 ba mi huo ren
	
	
//	freopen
//	freopen
//	freopen
//	freopen
//	freopen
	chang shi zeng jia chu jing lv
	
	jau jen loi paak ziu jiu gi zjyu caap doi
	
	class Reader (object):
		def __init__ (self) -> None:
			pass
		@staticmethod (?
		def open_file(self, filename) -> str:
			f = open (filename, "r")
			s = f.read()
			f.close()
			return s
		def read_line(self, line) -> str:
			pass
	kei saat pa bei mong gei zi fong dai loi yin ba
	*/
}
